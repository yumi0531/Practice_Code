from __future__ import print_function
from cgi import print_form
import platform
import module_practice as mm
mm.greeting("Yumi")
# using a funtion from a module, use the syntax: module_name.function_name

a = mm.person1["age"]
print(a)


# build-in module
x = platform.system()
print(x)
x = dir(platform)
print(x)
