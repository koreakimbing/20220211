#cogs/Recommandation.py
import discord
from discord.ext import commands
import random
import json
from bs3 import BeautifulSoup

class Recommandation(commands.Cog):
    def __init__(self, client):
        self.client = client
    
    @commands.Cog.listener()
    async def on_ready(self):
        print("Recommandation Cog is Ready")
        
def setup(client):
    client.add_cog(Recommandation(client))