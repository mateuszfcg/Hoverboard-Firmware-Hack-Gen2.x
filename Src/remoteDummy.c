#include "../Inc/target.h"
#include "../Inc/remote.h"
#include "../Inc/config.h"
#include "../Inc/defines.h"

#ifdef REMOTE_DUMMY


extern int32_t steer;
extern int32_t speed;
extern uint32_t msTicks;

void RemoteUpdate(void)
{
	#ifdef MASTER
		speed = 3 * (ABS((	((int32_t)msTicks/3+100) % 400) - 200) - 100);
		speed = CLAMP(speed , -1000, 1000);
	#else
		SetEnable(SET);
		SetPWM(-speed);
		ResetTimeout();
	#endif
	
	
}

void RemoteCallback(void){};

#endif