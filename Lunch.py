#cogs/Lunch.py
import discord
from discord.ext import commands
import json
import random

class Lunch(commands.Cog):
    def __init__(self, client):
        self.client = client
    
    @commands.Cog.listener()
    async def on_ready(self):
        print("Lunch Cog is Ready")

def setup(client):
    client.add_cog(Lunch(client))