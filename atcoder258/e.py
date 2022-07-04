
def main():
  n, q, x = map(int, input().split())
  w = list(map(int, input().split()))

  pref_sum = [0]

  for i in range(n):
    pref_sum.append(pref_sum[-1] + w[i])

  boxes, to = [0] * n, [0] * n

  for i in range(n):
    l, r = 1, x
    while l <= r:
      h = (l + r) // 2
      cycles, rem = h // n, h % n      
      total = pref_sum[-1] * cycles #+ _get_cycle_offset_sum(i, rem)
      e = (i + rem - 1) % n
      if e < i:
        total += pref_sum[-1] - pref_sum[i] + pref_sum[e + 1]
      else:
        total += pref_sum[e + 1] - pref_sum[i]
      if total >= x:
        boxes[i] = h
        r = h - 1
      else:
        l = h + 1
    to[i] = (i + boxes[i]) % n

  vis = {}
  cycle_start = None
  cycle = []
  i = 0
  while cycle_start is None:
    if i in vis:
      cycle_start = i
      break
    vis[i] = len(cycle)
    cycle.append(i)
    i = to[i]

  print(*boxes)
  print(*to)
  print(*cycle)

  ini_len = vis[cycle_start]
  cycle_len = len(cycle) - ini_len

  for _ in range(q):
    k = int(input()) - 1
    if k < ini_len:
      print(boxes[cycle[k]])
    else:
      cycle_idx = (k - ini_len) % cycle_len
      print(boxes[cycle[cycle_idx + ini_len]])



if __name__ == '__main__':
  main()
