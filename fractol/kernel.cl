__kernel void vadd( __global int *arr, int side_x, int side_y, int move_x, int move_y, int repeat, int color, double xmin, double xmax, double ymin, double ymax)
{
    double		xc;
    double 		yc;
    double 		x;
    double		y;
    int 		i;
    double 		xn1;
    double		yn1;
    double 		xn0;
    double 		yn0;
    int         dot;
    double      t;
    int         red;
    int         green;
    int         blue;

    dot = get_global_id(0);
    xc = xmin + ((double)(dot % 1500) - move_x) / 1500 * (xmax - xmin);
    yc = ymax + ((double)(dot / 1500) - move_y) / 1000 * (ymin - ymax);
    xn0 = 0;
    yn0 = 0;
    i = 0;
    while ((xn1 * xn1 + yn1 * yn1) <= 4.0 & i < repeat)
    {
    	xn1 = xn0 * xn0 - yn0 * yn0 + xc;
    	yn1 = 2.0 * xn0 * yn0 + yc;
    	xn0 = xn1;
        yn0 = yn1;
        i++;
    }
    if (color == 0 && i != repeat)
        arr[dot] = 0xFFFFFF;
    else
    {
        t = (double)i / (double)repeat;
        red = (int)((color) * (1 - t) * t * t * t * 255);
        green = (int)((color) * t * t * (1 - t) * (1 - t) * 255);
        blue = (int)((color) * (1 - t) * (1 - t) * (1 - t) * t * 255);
        arr[dot] = red * green * blue;
    }
}
