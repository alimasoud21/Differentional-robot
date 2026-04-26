import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    return LaunchDescription([

        Node(
            package='rplidar_ros',
            executable='rplidar_composition',
            output='screen',
            parameters=[{
                'serial_port': '/dev/ttyUSB0', # Change this if your LiDAR is on ttyUSB1, etc.
                'frame_id': 'laser',           # CRITICAL: Must match the URDF link name!
                'angle_compensate': True,
                'scan_mode': 'Standard'
            }]
        )
    ])
