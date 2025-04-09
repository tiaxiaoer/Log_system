FormatComponent中的format方法实现过于复杂，需要进行拆分和优化。
可以通过createFormatComponent方法来创建一个新的FormatComponent实例，
应该参考https://blog.csdn.net/Wzs040810/article/details/141298955?spm=1001.2014.3001.5502重新实现，可优化

LogFormatter.h实现笔记，坑点：
基本实现LogFormatter.h，实现了Format函数，实现了clear，实现了读取格式化字符串，但是没对
非法格式化字符串进行处理，后续可以加入异常机制，并且输出非单位字符串的进行的函数调用过多，应该可以去除中途步骤，直接输出，可优化，且每个Formatter对象都要重新初始化一个componentList列表，重新初始化一个formatFunc列表，性能过低，需要优化

2025-4-4 22:40 
使用marscode生成了LogFormatter.h中的Format函数的单元测试，但头文件gtest找不到，需要进行配置
安装了vcpkg（专属于C++的包管理工具）

    解决了git clone连接不到github.com的问题，问题为dns解析被污染，连接不到正确的ip地址，从https://www.ipaddress.com/website/github.com/网址中得到了正确的githubip地址，添加到windows的host文件中

2025-4-10 0：02
准备编写Makefile文件，编译测试LogFormatter模块的功能，使用gtest生成单元测试，将整个项目的文件结构标准化了，初步编写了LogFormatter中的Makefile文件，后续会继续完善
