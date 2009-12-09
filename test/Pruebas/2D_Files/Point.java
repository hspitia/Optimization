public class Point
{
	private double x,y;
	Point(double x, double y)
	{
		this.x=x;
		this.y=y;
	}
	public double getX()
	{
		return x;
	}
	public double getY()
	{
		return y;
	}
	public String toString()
	{
		return "["+x+";"+y+"]";
	}
}