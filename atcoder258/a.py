k = int(input())

mins = 21 * 60 + k
m, s = mins // 60, mins % 60

def _add_zero(s):
  ss = str(s)
  return ss if len(ss) > 1 else f'0{s}'

print(f'{m}:{_add_zero(s)}')

