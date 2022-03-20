
class fraction:
    #__init__ : object被產生出來就會執行
    def __init__(self, x, y):  # self為所有function第一個引數的預設，為物件的記憶體位址
        self.up = x  # 傳入的引數要賦值，所以放後面
        self.down = y
        # return x + "/" + y(和C的function思考概念不太一樣，有甚麼功能就用什麼function)

    # "+"為python提供的magic method，可改寫(magic method override)
    def __add__(self, another):  # 改寫為兩個物件的加法，self為本身的物件，another為傳入的另一個物件
        su = self.up
        sd = self.down
        au = another.up
        ad = another.down

        if(su*ad + au*sd) == (sd*ad):
            return fraction(1, 1)  # 算完的結果也為一個物件，需套用class
        else:
            # return (su*ad + au*sd) + "/" + (sd*ad)
            return fraction((su*ad + au*sd), (sd*ad))

    def printfff(self):
        print(str(self.up) + "/" + str(self.down))

    # 也可直接改寫原本的print()
    # def __str__(self):
    #     return str(self.up) + "/" + str(self.down)


p1 = fraction(1, 3)
p2 = fraction(1, 3)
p3 = p1+p2
p3.printfff()
# print(p3)


class car:
    door = 4  # class的屬性，由此class創造出來的所有物件皆共享類別屬性

    def __init__(self, color, name) -> None:
        self.color = color  # object的屬性，每個物件互相獨立且有各自的屬性值
        self.name = name

    def print_itself(self):
        print(self.color, self.name, self.door)


c1 = car("red", "toyota")
c2 = car("black", "porsche")

c1.print_itself()
c2.print_itself()
