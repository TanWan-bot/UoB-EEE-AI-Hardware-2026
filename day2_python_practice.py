print("1.")
print("Day2")

print("2.")
a = 15
b = 7
print("a + b =", a + b)
print("a - b =", a - b)
print("a * b =", a * b)
print("a / b =", a / b)

print("3.")
num = input("请输入一个数字：")
print("你的数字是：", num)

print("4.")
num1 = int(input("请输入第一个数字："))
num2 = int(input("请输入第二个数字："))
print("它们的和是：",num1 + num2)

print("5.")
age = int(input("请输入你的年龄："))
if age >= 18:
    print("成年了")
else:
    print("未成年")

print("6.")
score = int(input("请输入你的成绩（0-100）："))
if score >= 90:
    print("优秀")
elif score >= 60:
    print("及格")
else:
    print("不及格")

print("7.")
for i in range(0,11):
    print(i)

print("8.")
count = 0
while count < 5:
    print("Optimus要来了")
    count += 1

print("9.")
fruits = ["苹果","香蕉","橘子"]
print("列表长度：", len(fruits))
print("第二个水果：", fruits[1])

print("10.")
for fruit in fruits:
    print("今天吃：",fruit)