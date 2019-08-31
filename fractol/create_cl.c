#include "fractol.h"

void	func_error_1(int err)
{
	if (err == -7)
		ft_putstr("Building program error");
	else if (err == -8)
		ft_putstr("Creation kernel error");
	else if (err == -9)
		ft_putstr("Set arguments kernel error");
	else if (err == -10)
		ft_putstr("Write buffer error");
	else if (err == -11)
		ft_putstr("EnqueueNDRangeKernel error");
	else if (err == -12)
		ft_putstr("Read buffer error");
}

void	func_error(int	err)
{
	if (err == -1)
		ft_putstr("Platform ID error");
	else if (err == -2)
		ft_putstr("Devise ID error");
	else if (err == -3)
		ft_putstr("Creation context error");
	else if (err == -4)
		ft_putstr("Creation command queue error");
	else if (err == -5)
		ft_putstr("Creation buffer error");
	else if (err == -6)
		ft_putstr("Creation program error");
	func_error_1(err);
	exit (1);
}

int 	create_cl(t_fractol *fract)
{
	int		n;
	int		ret;
	t_cl	*cl;

	cl = fract->cl;
	n = SIDE_Y * SIDE_X;
	if ((ret = clGetPlatformIDs(1, &cl->platform_id, &cl->ret_num_platforms)) != OK)
		func_error(-1);
	if ((ret = clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_GPU, 1, &cl->device_id, &cl->ret_num_devices)) != OK)
		func_error(-2);
	if ((cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &ret)) && ret != OK)
		func_error(-3);
	if ((cl->cmd_queue = clCreateCommandQueue(cl->context, cl->device_id, 0, &ret)) && ret != OK)
		func_error(-4);
	if ((cl->program = clCreateProgramWithSource(cl->context, 1, (const char **) &fract->program_source,
												 (const size_t *) &fract->program_size, &ret)) && ret != OK)
		func_error(-6);
	if ((ret = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL)) != OK)
		func_error(-7);
	if ((cl->kernel = clCreateKernel(cl->program, "vadd", &ret)) && ret != OK)
		func_error(-8);
	cl->global_work_size[0] = n;
	if ((cl->memobjs = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_int) * SIDE_X * SIDE_Y, NULL, &ret)) && ret != OK)
		func_error(-5);
	set_arg(fract, cl);
	return (OK);
}

int 	set_arg(t_fractol *fract, t_cl *cl)
{
	int		ret;
	int		side_x;
	int		side_y;

	side_x = SIDE_X;
	side_y = SIDE_Y;
	ret = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->memobjs);
	ret |= clSetKernelArg(cl->kernel, 1, sizeof(int), &side_x);
	ret |= clSetKernelArg(cl->kernel, 2, sizeof(int), &side_y);
	ret |= clSetKernelArg(cl->kernel, 3, sizeof(double), &fract->x);
	ret |= clSetKernelArg(cl->kernel, 4, sizeof(double), &fract->y);
	ret |= clSetKernelArg(cl->kernel, 5, sizeof(int), &fract->repeat);
	ret |= clSetKernelArg(cl->kernel, 6, sizeof(int), &fract->color);
	ret |= clSetKernelArg(cl->kernel, 7, sizeof(double), &fract->xmin);
	ret |= clSetKernelArg(cl->kernel, 8, sizeof(double), &fract->xmax);
	ret |= clSetKernelArg(cl->kernel, 9, sizeof(double), &fract->ymin);
	ret |= clSetKernelArg(cl->kernel, 10, sizeof(double), &fract->ymax);
	if (ret != OK)
		func_error(-9);
	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs, CL_TRUE, 0, sizeof(cl_int) * SIDE_Y * SIDE_X, (cl_int *)fract->arr, 0, NULL, NULL)) != OK)
		func_error(-10);
	if ((ret = clEnqueueNDRangeKernel(cl->cmd_queue, cl->kernel, 1, NULL, cl->global_work_size, NULL, 0, NULL ,NULL)) != OK)
		func_error(-11);
	if ((ret = clEnqueueReadBuffer(cl->cmd_queue, cl->memobjs, CL_TRUE, 0, SIDE_X * SIDE_Y * sizeof(cl_int), (cl_int *)fract->arr, 0, NULL, NULL)) != OK)
		func_error(-12);
	return(OK);
}