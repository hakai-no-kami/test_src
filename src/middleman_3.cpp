#include "ros/ros.h"
#include "std_msgs/String.h"
#include "unistd.h"
#include <sstream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::normal_distribution<> d(2.0, 0.3);
class Middleman_3{
  public:
    Middleman_3(){
      sub = n.subscribe("chatter_3", 1, &Middleman_3::middlemanCallback,this);
      connected = n.advertise<std_msgs::String>("chatter_4", 1);
    }

    void middlemanCallback(const std_msgs::String::ConstPtr& msg){
      usleep(d(gen)*1000000);
      // temp.data = msg->data;
      ROS_INFO("I third intercepted: [%s]", msg->data.c_str());
      connected.publish(msg);
    }

  private:
    ros::NodeHandle n; 
    ros::Publisher connected;
    ros::Subscriber sub;
    std_msgs::String temp;
};

int main(int argc, char **argv){
  ros::init(argc, argv, "middleman_3");
  Middleman_3 middleman_3;
  ros::spin();
  return 0;
}

