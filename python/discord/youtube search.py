import requests
import json
import os

with open('config.json', 'r') as file:
    data = json.load(file)

os.environ['GOOGLE_API_KEY'] = data['GOOGLE_API_KEY']

response = requests.get('https://www.youtube.com/results?search_query=search')
o = response.json()
print(o)