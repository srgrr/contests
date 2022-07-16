T = int(input())
for _ in range(T):
  s = input().lower()
  print(['NO', 'YES'][int(s == 'yes')])
