import cv2

# image 
img_file = 'Car Image.jpg'
#video = cv2.VideoCapture('Cars_video.mp4')
#video = cv2.VideoCapture('Traffic.mp4')
video = cv2.VideoCapture('Real_time_Video.mp4')


# pre-trained car classifier
classifier_file = 'cars.xml'
car_tracker = cv2.CascadeClassifier(classifier_file)


while True:

    (read_succ, frame) = video.read()  # reading the currrent frame

    if read_succ:
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    else:
        break

    cars = car_tracker.detectMultiScale(gray_frame)
    for (x, y, w, h) in cars:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2)


    #display
    cv2.imshow("Car Detector", frame)

    cv2.waitKey(1)  # don't autoclose