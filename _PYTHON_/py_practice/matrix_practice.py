class qqq:

    def __init__(self, x):
        self._length = x  # 定義物件的屬性

    # def three(self):
    #     self._length *= 3

    def three(self):
        return qqq(self._length*3)  # 回傳同個class的物件

    def __str__(self) -> str:
        return str(self._length)


m1 = qqq(3)
m2 = m1.three()
print(m2)
# print(m1.three())
