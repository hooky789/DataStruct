CPPFLAGS= -Iinclude
CFLAGS= -g -Wall
CC=g++

src = $(wildcard *.cpp)
obj = $(patsubst %.cpp,%.o,$(src))
target = app

$(target):$(obj)
	$(CC) $^ $(LDFLAGS) -o $@

%.o:%.cpp
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY:clean

#彻底清除生生过程文件
clean:
	-rm -f *.o
	-rm -f app

#彻底清除生生过程文件和生成配置文件
distclean:
	rm /usr/bin/app

install:
	cp app  /usr/bin

