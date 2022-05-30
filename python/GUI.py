import tkinter as tk
import tkinter.messagebox
# def onOK():
#     # 取得輸入文字
#     print("Hello, {}確診.".format(entry.get()))

# # 標示文字
# label = tk.Label(menu, text='姓名')
# label.pack()  # 把label放在預設位置

# # 輸入欄位
# entry = tk.Entry(menu,     # 輸入欄位所在視窗
#                  width=20)  # 輸入欄位的寬度
# entry.pack()


# class menu():
menu = tk.Tk()
menu.title('Sign Language Interaction Tutorial System')
menu.geometry("800x500+250+150")  # window大小+左上角定位
menu['background'] = '#F4F1DE'

# ? 確認退出


def confirm_to_quit():
    if tk.messagebox.askokcancel('溫馨提示', '確定要退出嗎?'):
        menu.quit()


def createNewWindow():
    newWindow = tk.Toplevel(menu)
    labelExample = tk.Label(newWindow, text="New Window")
    buttonExample = tk.Button(newWindow, text="New Window button")

    labelExample.pack()
    buttonExample.pack()


# 按鈕
Tutorial_btn = tk.Button(
    menu, text="Tutorial Videos", bg='#F2CC8F', width=600, height=2, cursor='heart', command=createNewWindow).pack(padx=30, pady=15)

Practice_btn = tk.Button(
    menu, text="Practice", bg='#F2CC8F', width=600, height=2, cursor='heart').pack(padx=30, pady=15)

Quiz_btn = tk.Button(
    menu, text="Start A Quiz", bg='#F2CC8F', width=600, height=2, cursor='heart').pack(padx=30, pady=15)

quit_btn = tk.Button(
    menu, text='退出', command=confirm_to_quit).pack(anchor=tk.SW)
menu.mainloop()


# class Tutorial_Videos():
# video_btn1 = tk.Button(
#     menu, text="Videos", bg='#F2CC8F', width=20, height=2, cursor='heart').pack(padx=30, pady=15)


# menu.mainloop()
