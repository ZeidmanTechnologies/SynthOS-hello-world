// This is code in file "hello.c" 

extern int sync_variable;				

void helloTask()
{
	while (1)
	{
		printf("Hello task, ");
		//SynthOS_sleep();	// You can use sleep to release the CPU to the RTOS

        // But this usee SynthOS_wait for synchronization with other tasks and ISR
        SynthOS_wait(sync_variable < 3);
	}
}
