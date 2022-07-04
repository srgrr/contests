from itertools import product
n = int(input())
m = []
for _ in range(n):
  row = [int(x) for x in input()]
  m.append(row)

ans = 0

for d in product([-1, 0, 1], [-1, 0, 1]):
  if d != (0, 0):
    for i in range(n):
      for j in range(n):
        cur = [i, j]
        total = 0
        for _ in range(n):
          total = 10 * total + m[i][j]
          i = (i + d[0]) % n
          j = (j + d[1]) % n
        ans = max(ans, total)

print(ans)
