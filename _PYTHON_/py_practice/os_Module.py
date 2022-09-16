import os

lis1 = [f"hw{n}" for n in range(1, 11)]
# print(lis1)
# input版本
# while(True):
#     x = input()
#     if x == '0':
#         break
# lis1.append(x)

for i in lis1:
    os.mkdir(f"C:\\Users\\YUMI8\\desktop\\{i}")
    print("ok")
    # os.chdir(f"C:\\Users\\YUMI8\\desktop\\網頁程式設計\\作業解答\\{i}")

    # os.mkdir("hw" + y)
