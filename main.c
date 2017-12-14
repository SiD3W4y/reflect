#include "reflect.h"
#include <stdlib.h>

int add(int a,int b)
{
	return a+b;
}

int meh()
{
	printf("Hello World !\n");
}


REFLECT_ZONE(test1)
REFLECT_ADD_FN("int","add","Function adding two numbers",&add);
REFLECT_ADD_FN("int","printf","Print text duh",&printf);
REFLECT_ZONE_END

REFLECT_ZONE(test2)
REFLECT_ADD_FN("int","meh","Function printing hello world",&meh);
REFLECT_ZONE_END

int main()
{
	Function *f = reflect_getfn("meh");

	int (*meh_hook)();

	if(f != NULL){
		printf("Info : (0x%08x) %s %s -> %s\n",f->addr,f->type,f->name,f->description);
		meh_hook = f->addr;
		meh_hook();
	}else{
		printf("Function not found :(\n");
	}
}
