#cogs/Lunch.py
import discord
from discord.ext import commands
import json
import random

class Lunch(commands.Cog):
    def __init__(self, client):
        self.client = client
				# 데이터 불러오기
        with open("./data/lunch.json", 'r', encoding='utf-8') as f:
            self.lunchDict = json.load(f)
    
    @commands.Cog.listener()
    async def on_ready(self):
        print("Lunch Cog is Ready")

def setup(client):
    client.add_cog(Lunch(client))