public class PointDistance {
	private float distance;
	Point p1, p2;
	public PointDistance(Point p1, Point p2)
	{
		this.p1 = p1;
		this.p2 = p2;
		distance = p1.calculateDistance(p2);
	}

	public PointDistance() 
	{
		p1 = p2 = null;
		distance = Float.MAX_VALUE;
	}

	public Point getP1(){ return p1; }
	public Point getP2(){ return p2; }
	public float getDistance(){ return distance; }
}