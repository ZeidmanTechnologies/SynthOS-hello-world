// This is stored in file "world.c" 
int sync_variable;

void worldTask()
{
	while (1)
	{
		sync_variable = 3;
		printf(" World Task\n");

        // Call the synchronizaion task
        // SynthOS_call forces task context switch
        SynthOS_call(syncTask(sync_variable));
	}
}


void syncTask(int cnt_limit)
{
	int count;
	
	printf("sync task: ");
	for(count = 0; count < cnt_limit; count++)
	{
		printf("waiting %d... ", count);
	}
	
	sync_variable = 0;
}