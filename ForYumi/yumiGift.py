import pyautogui
import math
import time


def circle(x_len, y_len, draw_start=0.0, draw_finish=6.28318530718):
    # 用極座標
    list1 = list()
    i = draw_start
    while(i < draw_finish):
        x = x_len * math.cos(i)
        y = y_len * math.sin(i)
        list1.append([x, y])
        i += 0.17453292519

    for i in range(len(list1)-1):
        distance_x = list1[i+1][0]-list1[i][0]
        distance_y = list1[i+1][1]-list1[i][1]

        pyautogui.dragRel(distance_x, distance_y)


def heart(a=1, draw_start=0.0, draw_finish=6.28318530718):
    # parameter1: 係數
    list1 = list()
    i = draw_start
    while(i < draw_finish):
        x = (2 * a * (1 + math.sin(i))) * math.cos(i) + 10  # 微調
        y = (2 * a * (1 + math.sin(i))) * math.sin(i) - 4  # 微調
        list1.append([x, y])
        i += math.pi/12
    for i in range(len(list1)-1):
        distance_x = list1[i+1][0]-list1[i][0]
        distance_y = list1[i+1][1]-list1[i][1]

        pyautogui.dragRel(distance_x, distance_y)


SIZE = 1

pyautogui.click()  # 點擊進入小畫家

pyautogui.dragRel(0, 97*SIZE, 1, button="left")

pyautogui.dragRel(400*SIZE, 0, 1, button="left")


pyautogui.dragRel(0, -97*SIZE, 1, button="left")

x, y = pyautogui.position()
circle(203, 40)  # why是203不是200是因為實驗發現好像有誤差

pyautogui.moveRel(-331, 0, )
pyautogui.dragRel(0, -42, )
pyautogui.moveRel(0, 42, )

pyautogui.moveRel(33, 0, )
pyautogui.dragRel(0, -42, )
# save position to draw 1
x, y = pyautogui.position()

pyautogui.moveRel(-15, 0)
# draw 2
pyautogui.dragRel(-30, 0, )
pyautogui.dragRel(30, -29, )
pyautogui.dragRel(-14, -12, )
pyautogui.dragRel(-18, 10, )

pyautogui.moveTo(x+18, y)
# draw 1
pyautogui.dragRel(-30, 0)
pyautogui.moveRel(17, 0)
pyautogui.dragRel(3, -35)
pyautogui.moveRel(-3, -6)
pyautogui.dragRel(-13, 14)

pyautogui.moveRel(56, 28)
# draw body
pyautogui.dragRel(13, -44)
pyautogui.moveRel(70, 50)
# save position
x, y = pyautogui.position()
pyautogui.dragRel(-17, -44)
pyautogui.moveRel(12, -10)
circle(65, 50, math.pi/3, 2*math.pi-math.pi/3)
pyautogui.moveTo(x, y)
pyautogui.dragRel(7, -47)
pyautogui.moveRel(56, 50)
pyautogui.dragRel(-9, -52)

# draw my head
pyautogui.moveRel(12, -48)
circle(44, 44)

pyautogui.moveRel(-50, -7)
pyautogui.dragRel(-8, -6)
pyautogui.dragRel(-8, 6)
pyautogui.moveRel(-11, 20)
circle(8, 16)
pyautogui.moveRel(-2, -24)
pyautogui.dragRel(-16, 12)
pyautogui.moveRel(-20, 0)
pyautogui.dragRel(-16, -12)
pyautogui.dragRel(-16, 12)

# draw hair
pyautogui.moveRel(-20, -20)
pyautogui.dragRel(0, 80)
pyautogui.moveRel(12, -36)
pyautogui.dragRel(0, 36)
pyautogui.moveRel(12, -26)
pyautogui.dragRel(0, 26)

pyautogui.moveRel(0, -100)
pyautogui.dragRel(-12, 30)

for i in range(7):
    pyautogui.moveRel(12, -30)
    pyautogui.moveRel(10, 0)
    pyautogui.dragRel(-12, 30)

pyautogui.moveRel(20, 76)
circle(50, 15, draw_finish=math.pi*(7/6))


pyautogui.moveRel(120, -180)
heart(18)

print('\033[91m'+"-"*10)
print("Hello! my dear.")
print("Look at here")
time.sleep(6)
print("I ", end="")
print("bless ", end="")
print("my ", end="")
print("lovely ", end="")
print("baby ", end="")
print("who ", end="")
print("loves ", end="")
print("to ", end="")
print("cry", end="")
print(".", end="")
print(".", end="")
print(".")
time.sleep(6)
print("Happy birthday :)")
print("data.7z password: loveyou")
print("-"*10 + '\033[0m')
