from setuptools import setup

package_name = 'pneutrunk_solver'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='km',
    maintainer_email='ivan.virgala@tuke.sk',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "ik_solver = pneutrunk_solver.ik_solver:main",
            "plc_message = pneutrunk_solver.plc_message:main",
            "desired_position = pneutrunk_solver.desired_position:main"
        ],
    },
)
