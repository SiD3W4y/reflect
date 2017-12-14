#ifndef REFLECT_H
#define REFLECT_H

#define REFLECT_ARR_SIZE 50
#define REFLECT_ZONE(ns) __attribute__((__constructor__)) \
	void ns(){ \
		reflect_init();

#define REFLECT_ZONE_END }
#define REFLECT_ADD_FN(type,name,desc,addr) reflect_push_fn(type,name,desc,addr); 

typedef struct Function {
	char *name;
	char *type;
	char *description;
	void *addr;
} Function;

typedef struct ReflectList {
	Function **funcs;
	int size;
	int current;
} ReflectList;

extern ReflectList *_reflect_lst;

// Now defining the funcs used for reflection

void reflect_init();

Function *reflect_getfn(char *name);
void reflect_push_fn(char *type,char *name,char *description,void *addr);

#endif
