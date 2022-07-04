n, x = map(int, input().split())
stages = []

for _ in range(n):
  a, b = map(int, input().split())
  stages.append((a, b))

ans = 10 ** 30

movie_s, stage_s = 0, 0

for i in range(min(n, x)):
  movie, stage = stages[i]
  ans = min(ans, movie_s + stage_s + movie + (x - i) * stage)
  movie_s += movie
  stage_s += stage

print(ans)
