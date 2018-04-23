

int main(int argc ,const char* argvs[])
{

	int rc;
	rc = syscall(SYS_chmod,"./test.txt",S_IROTH|S_IRGRP|S:QW)
	
	return 0;

}


