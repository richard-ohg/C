
# for i in range(1,31):
# 	if i%5 == 0 and i%3 == 0:
# 		print("fizzbuzz")
# 	elif i%3 == 0:
# 		print("fizz")
# 	elif i%5 == 0:
# 		print("buzz")
# 	else:
# 		print(i)
		

# Fizz buzz en una sola linea
print(["fizzbuzz" if a%3==0 and a%5==0 else "buzz" if a%5==0 else "fizz" if a%3==0 else a for a in range(1,31)])