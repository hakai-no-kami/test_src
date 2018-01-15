#include "ros/ros.h"
#include "std_msgs/String.h"
#include "unistd.h"
#include <sstream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::normal_distribution<> d(2.0, 0.3);
class Middleman_2{
  public:
    Middleman_2(){
      sub_flag = 0;
      sub_2_flag = 0;
      sub = n.subscribe("chatter_2", 1, &Middleman_2::middlemanCallback,this);
      sub_2 = n.subscribe("chatter_4", 1, &Middleman_2::middlemanCallback_2,this);
      connected_1 = n.advertise<std_msgs::String>("middle_1", 1);
      connected_2 = n.advertise<std_msgs::String>("middle_2", 1);
      connected_3 = n.advertise<std_msgs::String>("middle_3", 1);
    }

    void middlemanCallback(const std_msgs::String::ConstPtr& msg){
      if(sub_2_flag == 1){
        usleep(d(gen)*1000000);
        ROS_INFO("I'm middlemanCallback,late, intercepted: [%s]", msg->data.c_str());
        connected_1.publish(msg);
        connected_2.publish(msg);
        connected_3.publish(msg);
        sub_2_flag = 0;
      }
      else{
        ROS_INFO("I'm middlemanCallback,first, intercepted: [%s]", msg->data.c_str());
        sub_flag = 1;
      }
    }
    void middlemanCallback_2(const std_msgs::String::ConstPtr& msg){
      if(sub_flag == 1){
        usleep(d(gen)*1000000);
        ROS_INFO("I'm middlemanCallback_2,late, intercepted: [%s]", msg->data.c_str());
        connected_1.publish(msg);
        connected_2.publish(msg);
        connected_3.publish(msg);
        sub_flag = 0;
      }
      else{
        ROS_INFO("I'm middlemanCallback_2,first, intercepted: [%s]", msg->data.c_str());
        sub_2_flag = 1;
      }
    }

  private:
    ros::NodeHandle n; 
    ros::Publisher connected_1;
    ros::Publisher connected_2;
    ros::Publisher connected_3;
    ros::Subscriber sub;
    ros::Subscriber sub_2;
    int sub_flag;
    int sub_2_flag;
};

int main(int argc, char **argv){
  ros::init(argc, argv, "middleman_2");
  Middleman_2 middleman_2;
  ros::spin();
  return 0;
}
