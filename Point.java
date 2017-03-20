/**
 * Created by shafai on 2017-03-18.
 */
public class Point {
        // the coordinates of the point
        private double x;
        private double y;
        public Point (double x, double y) {
            this.x = x;
            this.y = y;
        }
        public double getX () {
            return this.x;
        }
        public double getY () {
            return this.y;
        }
        // distance returns the distance between this point and a given point
        public double distance (Point p) {
            return Math.sqrt ((p.x - this.x) * (p.x - this.x) +
                    (p.y - this.y) * (p.y - this.y));
        }

        public String toString(){
            return "("+this.x +"," + this.y+")";
        }
        public static Point nearestPoint(Point[] points, Point point){
            Point p = points[0];
            for(int i = 0; i < points.length; i++){
                if(points[i].distance(point) < p.distance(point)){
                    p = points[i];
                }
            }
           return p;
        }
        public static Point internalPoint(Point[] points,Point radius){
            Point pointInside = points[0];
            for(int i = 0; i < points.length; i++){
                if(points[i].distance(pointInside) <= pointInside.distance(radius) ){
                    pointInside = points[i];
                }
            }
            return pointInside;
        }
        public static void main(String[] args){
            Point[] points = {new Point(1,2),
                              new Point(2,3),
                              new Point(5,2)};

            Point point = new Point (1,1);
            Point radius = new Point(3,5);
            Point nearestPoint = nearestPoint(points,point);
            Point internalPoint= internalPoint(points,radius);
            System.out.println(nearestPoint+"   " +internalPoint);
        }

    }

