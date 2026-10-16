"""Check all ten exercises against examples and independent expected results."""
from pathlib import Path
import argparse
import math
import re
import subprocess

parser = argparse.ArgumentParser()
parser.add_argument('--bin-dir', default='build')
args = parser.parse_args()
binary = Path(args.bin_dir).resolve()
runs = 0


def run(exercise, data='', valid=True):
    global runs
    path = binary / ('ex_' + exercise)
    if path.with_suffix('.exe').exists():
        path = path.with_suffix('.exe')
    result = subprocess.run([str(path)], input=data, text=True,
                            capture_output=True, timeout=30)
    runs += 1
    assert (result.returncode == 0) == valid, (exercise, result)
    return result.stdout


out = run('3_17', '100\n5394.78\n1000\n500\n5500\n'
                    '200\n1000\n123.45\n321\n1500\n'
                    '300\n500\n274.73\n100\n800\n-1\n')
assert 'Account: 100\nCredit limit: 5500.00\nBalance: 5894.78' in out
assert out.count('Credit limit exceeded.') == 1
assert 'Account: 200' not in out and 'Account: 300' not in out
assert 'exceeded' not in run('3_17', '1\n100\n10\n10\n100\n-1\n')
assert 'Account:' not in run('3_17', '-1\n')

out = run('3_18', '5000\n1234.56\n0\n-1\n')
assert re.findall(r'Salary is \$(\d+\.\d{2})', out) == ['650.00', '311.11', '200.00']
run('3_18', '-2\n', False)

out = run('3_19', '1000\n0.1\n365\n1000\n0.08375\n224\n1000\n0\n0\n-1\n')
assert re.findall(r'interest charge is \$(\d+\.\d{2})', out) == ['100.00', '51.40', '0.00']
run('3_19', '1000\n-0.1\n', False)

out = run('3_20', '39\n10\n40\n10\n41\n10\n0\n10\n-1\n')
assert re.findall(r'Salary is \$(\d+\.\d{2})', out) == ['390.00', '400.00', '415.00', '0.00']
run('3_20', '10\n-1\n', False)

for length, breadth in [(3, 12), (1, 5), (5, 1), (1, 1), (4, 7)]:
    out = run('3_33', f'{length} {breadth}\n').split(': ', 1)[1]
    rows = out.splitlines()
    assert len(rows) == length and all(len(row) == breadth for row in rows)
    for i, row in enumerate(rows):
        for j, char in enumerate(row):
            border = i in (0, length - 1) or j in (0, breadth - 1)
            assert char == ('+' if border else ' ')
run('3_33', '0 5\n', False)
run('3_33', 'hello\n', False)

out = run('4_15')
sections = re.findall(r'Interest rate: ([\d.]+)%\n(.*?)(?=Interest rate:|\Z)', out, re.S)
assert [float(rate) for rate, _ in sections] == [10, 10.5, 11, 11.5, 12]
for rate, section in sections:
    rows = re.findall(r'^\s*(\d+)\s+([\d.]+)\s*$', section, re.M)
    assert [int(year) for year, _ in rows] == list(range(1, 16))
    for year, amount in rows:
        assert amount == f'{5000 * (1 + float(rate) / 100) ** int(year):.2f}'

out = run('4_16')
sections = re.findall(r'\(([ABCD])\)\n(.*?)(?=\([ABCD]\)|\Z)', out, re.S)
assert [label for label, _ in sections] == list('ABCD')
for label, section in sections:
    rows = section.rstrip('\n').splitlines()
    assert len(rows) == 10
    for index, row in enumerate(rows):
        stars = index + 1 if label in 'AD' else 10 - index
        spaces = 10 - stars if label in 'CD' else 0
        assert row == ' ' * spaces + '*' * stars

out = run('4_27')
triples = [tuple(map(int, line.split())) for line in out.splitlines()[1:]]
expected = set()
for a in range(1, 501):
    for b in range(1, 501):
        square = a * a + b * b
        c = math.isqrt(square)
        if c <= 500 and c * c == square:
            expected.add((a, b, c))
assert len(triples) == len(set(triples))
assert set(triples) == expected
assert (300, 400, 500) in expected and (4, 3, 5) in expected

out = run('4_28', '1\n1200\n2\n40 10\n2\n41 10\n3\n1000\n4\n12 2.5\n9\n-1\n')
assert re.findall(r'Weekly pay: \$(\d+\.\d{2})', out) == ['1200.00', '400.00', '415.00', '307.00', '30.00']
assert 'Invalid pay code.' in out
assert 'Weekly pay:' not in run('4_28', '-1\n')
run('4_28', '2\n-2 10\n', False)
run('4_28', '4\n2 -1\n', False)

out = run('4_31')
rows = out.splitlines()
assert len(rows) == 9
assert [len(row.strip()) for row in rows] == [1, 3, 5, 7, 9, 7, 5, 3, 1]
for index, row in enumerate(rows):
    span = 9 - 2 * abs(4 - index)
    assert row == ' ' * ((9 - span) // 2) + '*' * span

print(f'PASS: all 10 exercises, {runs} program runs; {len(expected)} Pythagorean triples verified')
