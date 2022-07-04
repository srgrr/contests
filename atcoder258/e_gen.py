import random
random.seed(id('kavya'))

print('200000 200000 1000000000')

print(' '.join(str(random.randint(1, 100)) for _ in range(200000)))
for _ in range(200000):
  print(random.randint(1, 100))
