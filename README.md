# llvm pass skeleton 
    this reposity shows the way to write llvm pass by two ways, dynamic and excutable.

## dynamic
    this will generate dynamic library and use it by `opt -load`.
## excutable
    this will generate an excutable file, and you can run it directly.

-----
# how to build?
    (```)
        cd DynamicLib/test
        ./run.sh
    (```)

    tips: remember to modify the llvm path in shell script.