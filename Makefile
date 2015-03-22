OPENFST=$(HOME)/software/openfst-1.4.1
NAME=fstcompose-speedtest

all:
	g++ -std=c++0x -O3 -I$(OPENFST)/include $(NAME).cc -o $(NAME) -L$(OPENFST)/lib -lfst -ldl -lrt

