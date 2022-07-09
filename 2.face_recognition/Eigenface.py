import cv2
import numpy as np

if __name__ == "__main__":
    train_images = list()
    labels = list()
    test_image = None

    recoginer = cv2.face.EigenFaceRecognizer_create()
    recoginer.train(train_images, labels)
    label, confidence = recoginer.predict(test_image)

    print("Matching label :", label)
    print("Credibility: ", confidence)
