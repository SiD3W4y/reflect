#include <stdlib.h>

#include "reflect.h"

ReflectList *_reflect_lst = NULL;

// Function called by the macros
void reflect_init()
{
	if(_reflect_lst == NULL){
		_reflect_lst = malloc(sizeof(ReflectList));
		_reflect_lst->funcs = malloc(sizeof(Function*) * REFLECT_ARR_SIZE);
		_reflect_lst->size = REFLECT_ARR_SIZE;
		_reflect_lst->current = 0;
	}
}

void reflect_push_fn(char *type,char *name,char *description,void *addr){
	Function *f = malloc(sizeof(Function));

	f->type = type;
	f->name = name;
	f->description = description;
	f->addr = addr;
	
	_reflect_lst->funcs[_reflect_lst->current] = f;
	_reflect_lst->current += 1;
}

Function *reflect_getfn(char *name)
{
	Function *f;

	for(int i=0;i < _reflect_lst->current;i++){
		f = _reflect_lst->funcs[i];
		
		if(strcmp(name,f->name) == 0){
			return f;
		}
	}

	return NULL;
}
