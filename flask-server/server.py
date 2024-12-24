from flask import Flask, request
import csv
from datetime import datetime

app = Flask(__name__)

@app.route('/data', methods=['POST'])
def receive_data():
    data = request.json
    if data:
        with open('data.csv', mode='a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([datetime.now(), data['temperature'], data['humidity']])
        return "Datos recibidos!", 200
    return "Error: Datos inválidos", 400

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)
