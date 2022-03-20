import sys
print(sys.version)
# copy()裡不能有keyword
thislist = ["apple", "banana", "cherry"]
# mylist = thislist.copy(reverse=True)
mylist = thislist.copy()
print(mylist)
