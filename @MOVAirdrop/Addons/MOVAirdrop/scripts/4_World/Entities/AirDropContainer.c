class AirDropContainer extends House
{
	void AirDropContainer()
	{
		EntityAI signal = Particle.Play(ParticleList.RDG2, this);
		signal.SetOrientation("0 0 0");
	}
}