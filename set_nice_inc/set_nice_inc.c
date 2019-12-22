#include <asm/errno.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_set_nice_inc(pid_t pid, int value)
{
    struct task_struct *p = find_task_by_vpid(pid);

    if (!p)
        return -ESRCH;

    p->nice_inc = value;
    return 0;
}
