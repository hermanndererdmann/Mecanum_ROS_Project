import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3

def joy_callback(data):
    
    # Erzeuge eine Instanz der Twist-Nachricht
    twist_msg = Twist()
    
    # Weise Werte dem Vector3-Feld zu
    twist_msg.linear.x = data.axes[0]
    twist_msg.linear.y = data.axes[1]
    twist_msg.linear.z = 0.0
    
    # Weise Werte dem angularen Vector3-Feld zu
    twist_msg.angular.x = 0.0
    twist_msg.angular.y = 0.0
    twist_msg.angular.z = data.axes[4]
    
    # Veröffentliche die Twist-Nachricht
    pub.publish(twist_msg)

def joy_twist_bridge():
    rospy.init_node('joy_twist_bridge', anonymous=True)

    # Abonniere das Topic für die Joy-Nachricht
    rospy.Subscriber('joy', Joy, joy_callback)

    # Erstelle einen Publisher für die Twist-Nachricht
    pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)

    rospy.spin()

if __name__ == '__main__':
    joy_twist_bridge()







