import cv2

img = cv2.imread("imagem.jpg")  # Carregar a imagem
cv2.imshow("Imagem", img)  # Exibir a imagem
cv2.waitKey(0)  # Espera pressionar uma tecla
cv2.destroyAllWindows()  # Fecha a janela

img_resized = cv2.resize(img, (200, 200))
cv2.imshow("Redimensionada", img_resized)
cv2.waitKey(0)
cv2.destroyAllWindows()

img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow("Escala de Cinza", img_gray)
cv2.waitKey(0)
cv2.destroyAllWindows()

img_rect = img.copy()
cv2.rectangle(img_rect, (50, 50), (200, 200), (0, 255, 0), 3)  # Retângulo verde
cv2.imshow("Retângulo", img_rect)
cv2.waitKey(0)
cv2.destroyAllWindows()
