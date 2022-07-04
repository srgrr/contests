n, q = map(int, input().split())
s = input()

i0 = 0

for _ in range(q):
  t, x = map(int, input().split())
  if t == 1:
    i0 = (i0 - x) % n
  else:
    print(s[(i0 + x - 1) % n])

