public class Point {
	private float x, y;
	public Point(float x, float y) {
		this.x = x;
		this.y = y;
	}

	public float getX(){ return x; }
	public float getY(){ return y; }

	public float calculateDistance(Point p) {
		return (float)Math.sqrt(Math.pow(x - p.getX(), 2) + Math.pow(y - p.getY(), 2));
	}
}