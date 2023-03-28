all:
	rm -f uavrt_tag_analyzer
	rm -f *.o
	rm -f codegen/exe/uavrt_tag_analyzer/*.o
	make -f matlab-coder-utils/Makefile PRODUCT_NAME=uavrt_tag_analyzer -j4
