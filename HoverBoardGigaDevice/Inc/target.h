#ifdef GD32E230
	#include "gd32e23x.h"
	#define TARGET_nvic_irq_enable(a, b, c){nvic_irq_enable(a, b);}
	#define TARGET_nvic_priority_group_set(a)	// that function does not exist for this target = not needed ?
#else
	#include "gd32f1x0.h"
	
	#define TARGET_nvic_irq_enable(a, b, c){nvic_irq_enable(a, b, c);}
	#define TARGET_nvic_priority_group_set(a){nvic_priority_group_set(a);}
#endif
