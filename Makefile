
CC:=g++
exe:=LeetCode
obj:=LeetCode.o

all:$(obj)
	$(CC) -o $(exe) $(obj)  
%.o:%.c
	$(CC) -c $^ -o $@

clean:
	rm -rf $(obj) $(exe)

run:
	./$(exe)