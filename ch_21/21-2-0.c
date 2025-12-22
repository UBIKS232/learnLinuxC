#define device_init_wakeup(dev,val) \
                { device_can_wakeup(dev) = !!(val); \
                device_set_wakeup_enable(dev,val); }

if (n > 0)
	device_init_wakeup(d, v);
else
	continue;

/* gcc -E 
# 0 "./21-2-0.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "./21-2-0.c"




if (n > 0)
 { device_can_wakeup(d) = !!(v); device_set_wakeup_enable(d,v); }; // < -- error
else
 continue;

 */