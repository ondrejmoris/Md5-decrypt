PATH:=${PATH}:/usr/local/cuda-10.2/bin
CC:=nvcc
OPT:=-Xcompiler -fPIC 


main1: cuda1.o main1.o
	${CC} ${OPT} $^ -o $@

cuda1.o: cuda1.cu
	${CC} ${OPT} -c $^  -o $@

main1.o: main1.cpp
	${CC} ${OPT} -c $^  -o $@

clean:
	rm *.o main1
