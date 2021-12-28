# Car360CameraPanel
This is a button panel for Chinese 360 Car Cameras that are usually controlled by IR remotes. 

# Objective:
The intent is to create a simple button panel on the centre consol of the car that can easily control the cameraviews without resorting to taking the remote, pointing at it, etc. 
The system should have only minimal buttons that are must have to quickly see all around the vehicle. 

# Schematic
First the IR Codes of the remote are identified using the IRRemote library and the ReceiveDump example script. 
Three push buttons are connected to an arduino which then sends the same signal that the IR remote would send. This signal is a demodulated signal, and is sent directly to the signal pin of the 360 DVR. This is achieved by tapping into the signal wire that goes into the IR reciever. 
Note: For this to work, the ground of the arduino and the DVR must be the same. This is achieved by connecting the Arduino to the car's USB port. 


# Files
1. The Arduino Sketch is included.
2. The STL files for the 3d printed panel body is included. 


# TODO:
More Aesthetic panel body
Photos
