class AirDropContainer extends House
{
	void AirDropContainer()
	{
		EntityAI signal = Particle.Play(ParticleList.RDG2, this, vector.Zero, vector.Zero);
		signal.SetOrientation("0 0 0");
	}
}